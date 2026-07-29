// 导入依赖
const fs = require('fs'); // 文件系统模块，用于读写文件
const jsonc = require('jsonc'); // 支持注释的JSON解析器

// 配置管理器类 - 负责加载和管理所有配置文件
class ConfigManager {
    constructor() {
        // 加载所有配置文件
        this.config = this.loadConfig('./config/config.json'); // 主配置文件
        this.block = this.loadConfig('./config/block.json'); // 方块配置
        this.ore_feature = this.loadConfig('./config/ore_feature.json'); // 矿类地物配置
        this.paths = this.initPaths(); // 初始化路径
    }

    // 加载JSON配置文件
    loadConfig(path) {
        return jsonc.parse(fs.readFileSync(path, 'utf8'));
    }

    // 初始化所有路径，基于配置文件中的文件夹名称
    initPaths() {
        const { BPFolderName, RPFolderName } = this.config;
        return {
            // 行为包生成路径
            bp: `../development_behavior_packs/${BPFolderName}/`,
            // 资源包生成路径
            rp: `../development_resource_packs/${RPFolderName}/`,
            // 插件配置生成路径
            plugin: `../../config/`,
        };
    }
}

// 清单文件生成器类 - 负责创建manifest.json文件
class ManifestGenerator {
    constructor(configManager) {
        this.cfg = configManager.config; // 主配置
        this.paths = configManager.paths; // 路径配置
        // 内置的行为包模板
        this.bpTemplate = {
            format_version: 2,
            header: {
                name: '',
                description: '',
                uuid: '71b8b647-075b-4ae0-a384-56a55ad94f0a',
                version: [],
                min_engine_version: [],
            },
            modules: [
                {
                    type: 'data',
                    uuid: '9ea8ec7d-3d2a-46dd-a7a8-e6f492dee31c',
                    version: [],
                },
                {
                    type: 'script',
                    language: 'javascript',
                    uuid: '07bfb190-1c7e-402e-8383-a315af6c9be3',
                    version: [],
                    entry: 'scripts/main.js',
                },
            ],
            dependencies: [
                {
                    uuid: '45999252-d97c-4923-9c2b-18cf29d5d2d6',
                    version: [],
                },
                {
                    module_name: '@minecraft/server',
                    version: '',
                },
            ],
        };
        // 内置的资源包模板
        this.rpTemplate = {
            format_version: 2,
            header: {
                name: '',
                description: '',
                uuid: '45999252-d97c-4923-9c2b-18cf29d5d2d6',
                version: [],
                min_engine_version: [],
            },
            modules: [
                {
                    type: 'resources',
                    uuid: '1823463d-43d8-497f-938c-74ee46e385ea',
                    version: [],
                },
            ],
            dependencies: [
                {
                    uuid: '71b8b647-075b-4ae0-a384-56a55ad94f0a',
                    version: [],
                },
            ],
        };
    }

    // 生成行为包清单文件
    generateBP() {
        const manifest = this.prepareManifest(this.bpTemplate);
        this.writeManifest(this.paths.bp, manifest);
    }

    // 生成资源包清单文件
    generateRP() {
        const manifest = this.prepareManifest(this.rpTemplate);
        this.writeManifest(this.paths.rp, manifest);
    }

    // 准备清单文件内容
    prepareManifest(manifestTemplate) {
        // 深拷贝模板，避免修改原对象
        const manifest = JSON.parse(JSON.stringify(manifestTemplate));
        const {
            addonsName,
            addonsDescription,
            addonsVersion,
            gameVersion,
            serverModuleVersion,
        } = this.cfg;

        // 设置清单头部信息
        manifest.header.name = addonsName; // 附加包名称
        manifest.header.description = addonsDescription; // 附加包描述
        manifest.header.version = addonsVersion; // 附加包版本
        manifest.header.min_engine_version = gameVersion; // 最低游戏版本

        // 设置所有模块的版本号
        manifest.modules.forEach((module) => {
            module.version = addonsVersion;
        });

        // 设置依赖项的版本
        manifest.dependencies?.forEach((dep) => {
            if (dep.module_name === '@minecraft/server') {
                dep.version = serverModuleVersion; // Minecraft服务器模块版本
            } else {
                dep.version = addonsVersion; // 其他依赖版本
            }
        });

        return manifest;
    }

    // 写入清单文件到指定路径
    writeManifest(basePath, manifest) {
        FileUtil.writeFile(
            `${basePath}manifest.json`,
            jsonc.stringify(manifest, null, 4)
        );
    }
}

// 纹理索引生成器类 - 负责生成item_texture.json和terrain_texture.json
class TextureIndexGenerator {
    constructor(configManager) {
        this.paths = configManager.paths; // 路径配置

        // 检测是否为武器/工具的字符串数组
        this.weaponKeywords = ['sword', 'axe', 'pickaxe', 'shovel', 'hoe'];

        // itemAttachables模板
        this.itemAttachablesTemplate = {
            format_version: '1.10.0',
            'minecraft:attachable': {
                description: {
                    identifier: '',
                    materials: {
                        default: 'entity_alphatest',
                        enchanted: 'entity_alphatest_glint',
                    },
                    textures: {
                        default: '',
                        enchanted: 'textures/misc/enchanted_item_glint',
                    },
                    geometry: {
                        default: 'geometry.cb.item_weapon',
                        offhand: 'geometry.cb.item_weapon.offhand',
                    },
                    animations: {
                        default: 'animation.cb.item_weapon',
                    },
                    scripts: {
                        animate: ['default'],
                    },
                    render_controllers: [
                        {
                            'controller.render.cb_weapon':
                                "c.item_slot == 'main_hand'",
                        },
                        {
                            'controller.render.cb_weapon.offhand':
                                "c.item_slot == 'off_hand'",
                        },
                    ],
                },
            },
        };
    }

    // 生成物品纹理索引文件
    generateItemTextureIndex() {
        const textureDir = `${this.paths.rp}textures/items`;
        if (!fs.existsSync(textureDir)) return;

        const textureData = {};
        const files = fs.readdirSync(textureDir, {
            withFileTypes: true,
            recursive: true,
        });

        files.forEach((file) => {
            if (!file.isFile()) return;

            const match = file.name.match(/\.(png|tga)$/);
            if (!match) return;

            const name = file.name.replace(match[0], '');

            let relativePath = '';
            if (file.parentPath) {
                const pathParts = file.parentPath
                    .replace(/\\/g, '/')
                    .split('/');
                const texturesIndex = pathParts.indexOf('textures');
                if (texturesIndex !== -1) {
                    const afterTextures = pathParts.slice(texturesIndex + 2);
                    if (afterTextures.length > 0) {
                        relativePath = afterTextures.join('/');
                    }
                }
            }

            let texturePath;
            if (relativePath) {
                texturePath = `textures/items/${relativePath}/${name}`;
            } else {
                texturePath = `textures/items/${name}`;
            }

            textureData[name] = {
                textures: texturePath,
            };

            // 检测是否为武器/工具，如果是则生成attachable文件
            if (this.isWeaponItem(name)) {
                this.generateAttachableFile(name, texturePath, relativePath);
            }
        });

        const itemTexture = {
            resource_pack_name: 'vanilla',
            texture_name: 'atlas.items',
            texture_data: textureData,
        };

        FileUtil.writeFile(
            `${this.paths.rp}textures/item_texture.json`,
            jsonc.stringify(itemTexture, null, 4)
        );
    }

    // 检测是否为武器/工具
    isWeaponItem(itemName) {
        const lowerName = itemName.toLowerCase();
        return this.weaponKeywords.some((keyword) =>
            lowerName.includes(keyword)
        );
    }

    // 生成attachable文件
    generateAttachableFile(itemName, texturePath, relativePath) {
        try {
            const attachable = JSON.parse(
                JSON.stringify(this.itemAttachablesTemplate)
            );

            let identifier;
            const hasVanilla = texturePath.includes('mc');
            const hasCB = texturePath.includes('cb');

            if (hasVanilla) {
                identifier = `minecraft:${itemName}`;
            } else if (hasCB) {
                identifier = `cb:${itemName}`;
            } else {
                identifier = `cb:${itemName}`;
            }

            attachable['minecraft:attachable'].description.identifier =
                identifier;
            attachable['minecraft:attachable'].description.textures.default =
                texturePath;

            let fileName = itemName + '.json';
            let attachableFilePath;
            if (relativePath) {
                attachableFilePath = `${this.paths.rp}attachables/${relativePath}/${fileName}`;
                FileUtil.ensureDir(attachableFilePath);
            } else {
                attachableFilePath = `${this.paths.rp}attachables/${fileName}`;
                const attachablesDir = `${this.paths.rp}attachables/`;
                FileUtil.ensureDir(`${attachablesDir}dummy.json`);
            }

            FileUtil.writeFile(
                attachableFilePath,
                jsonc.stringify(attachable, null, 4)
            );

            const displayPath = relativePath
                ? `${relativePath}/${fileName}`
                : fileName;
            console.log(`已生成attachable文件: ${displayPath} (${identifier})`);
        } catch (error) {
            console.error(
                `生成attachable文件时发生错误 (${itemName}): ${error.message}`
            );
        }
    }

    // 生成地形纹理索引文件（修改后支持子目录）
    generateTerrainTextureIndex() {
        const textureDir = `${this.paths.rp}textures/blocks`;
        if (!fs.existsSync(textureDir)) return;

        const textureData = {};
        const files = fs.readdirSync(textureDir, {
            withFileTypes: true,
            recursive: true,
        });

        files.forEach((file) => {
            if (!file.isFile()) return;

            const match = file.name.match(/\.(png|tga)$/);
            if (!match) return;

            const name = file.name.replace(match[0], '');

            // 计算相对路径，支持子目录
            let relativePath = '';
            if (file.parentPath) {
                const pathParts = file.parentPath
                    .replace(/\\/g, '/')
                    .split('/');
                const texturesIndex = pathParts.indexOf('textures');
                if (texturesIndex !== -1) {
                    // 跳过 textures 和 blocks
                    const afterTextures = pathParts.slice(texturesIndex + 2);
                    if (afterTextures.length > 0) {
                        relativePath = afterTextures.join('/');
                    }
                }
            }

            let texturePath;
            if (relativePath) {
                texturePath = `textures/blocks/${relativePath}/${name}`;
            } else {
                texturePath = `textures/blocks/${name}`;
            }

            textureData[name] = {
                textures: texturePath,
            };
        });

        const terrainTexture = {
            resource_pack_name: 'vanilla',
            texture_name: 'atlas.terrain',
            padding: 8,
            num_mip_levels: 4,
            texture_data: textureData,
        };

        FileUtil.writeFile(
            `${this.paths.rp}textures/terrain_texture.json`,
            jsonc.stringify(terrainTexture, null, 4)
        );
    }
}

// 方块注册生成器类 - 负责生成方块相关文件
class BlockGenerator {
    constructor(configManager) {
        this.cfg = configManager.config; // 主配置
        this.blockConfig = configManager.block; // 方块配置文件内容
        this.paths = configManager.paths; // 路径配置

        // 存储方块战利品数据，用于生成block_loot.json
        this.blockLootData = {};

        // 方块模板对象 - 包含默认配置
        this.blockTemplate = {
            format_version: '',
            'minecraft:block': {
                description: {
                    identifier: '',
                    menu_category: {},
                },
                components: {},
            },
        };

        // 初始化 blocks 对象，包含基础的格式版本
        this.blocks = {
            format_version: [1, 0, 0],
            frame: {
                blockshape: 'invisible',
                textures: 'itemframe_background',
                sound: 'itemframe',
            },
            glow_frame: {
                blockshape: 'invisible',
                textures: 'itemframe_background',
                sound: 'itemframe',
            },
        };
    }

    // 生成方块文件
    generateBlockFiles() {
        console.log('开始生成方块文件...');

        // 检查是否有方块配置
        if (
            !this.blockConfig ||
            !this.blockConfig.blocks ||
            !Array.isArray(this.blockConfig.blocks)
        ) {
            console.warn('没有找到方块配置，跳过方块文件生成');
            return;
        }

        // 确保blocks目录存在
        const blocksDir = `${this.paths.bp}blocks/`;
        FileUtil.ensureDir(`${blocksDir}dummy.json`); // 创建目录

        // 清空方块战利品数据
        this.blockLootData = {};

        // 遍历方块配置数组
        this.blockConfig.blocks.forEach((blockData) => {
            this.generateSingleBlockFile(blocksDir, blockData);
        });

        // 生成完所有方块文件后，写入 blocks.json
        this.writeBlocksJson();

        // 写入矿石数据到 block_loot.json
        this.writeBlockLootDataJson();

        console.log(`成功生成 ${this.blockConfig.blocks.length} 个方块文件`);
    }

    // 生成单个方块文件
    generateSingleBlockFile(blocksDir, blockData) {
        // 检查必要字段
        if (!blockData.identifier) {
            console.warn('跳过缺少identifier的方块配置:', blockData);
            return;
        }

        // 如果方块有loot属性，则添加到方块战利品数据中
        if (blockData.loot) {
            this.blockLootData[blockData.identifier] = blockData.loot;
            console.log(`已添加方块战利品数据: ${blockData.identifier}`);
        }

        // 创建方块对象副本
        const blockObject = JSON.parse(JSON.stringify(this.blockTemplate));

        // 设置基本属性
        blockObject.format_version = this.blockConfig.format_version;
        blockObject['minecraft:block'].description.identifier =
            blockData.identifier;

        // 设置菜单分类
        if (blockData.menu_category) {
            blockObject['minecraft:block'].description.menu_category = {
                ...blockObject['minecraft:block'].description.menu_category,
                ...blockData.menu_category,
            };
        }

        // 设置组件
        const components = blockObject['minecraft:block'].components;

        // 设置显示名称
        components['minecraft:display_name'] =
            'tile.' + blockData.identifier + '.name';

        // 设置挖掘时间（根据硬度计算）
        if (blockData.hardness !== undefined) {
            components['minecraft:destructible_by_mining'] = {};
            components['minecraft:destructible_by_mining'].seconds_to_destroy =
                blockData.hardness * 1.5; // 根据硬度计算挖掘时间
        }

        // 设置爆炸抗性
        if (blockData.explosion_resistance !== undefined) {
            components['minecraft:destructible_by_explosion'] = {};
            components[
                'minecraft:destructible_by_explosion'
            ].explosion_resistance = blockData.explosion_resistance;
        }

        // 设置方块模型和贴图
        if (blockData.geometry !== undefined) {
            components['minecraft:geometry'] = {};
            components['minecraft:geometry'] = blockData.geometry;
        }
        if (blockData.material_instances !== undefined) {
            components['minecraft:material_instances'] = {};
            components['minecraft:material_instances'] =
                blockData.material_instances;
        }

        // 设置显示名称
        components['minecraft:map_color'] = '#ffffff';

        // 设置掉落物为空以便后期调整掉落物
        components['minecraft:loot'] = 'loot_tables/blocks/empty.json';

        // 添加光源发射组件（如果存在）
        if (blockData.light_emission !== undefined) {
            components['minecraft:light_emission'] = blockData.light_emission;
        }

        // 设置工作台
        if (blockData.crafting_table !== undefined) {
            components['minecraft:crafting_table'] = blockData.crafting_table;
        }

        // 添加tag
        if (blockData.tags !== undefined) {
            components['minecraft:tags'] = blockData.tags;
        }

        // 设置方块方向
        if (blockData.traits !== undefined) {
            blockObject['minecraft:block']['description']['traits'] = {};
            blockObject['minecraft:block']['description']['traits'] =
                blockData.traits;
        }
        if (blockData.permutations !== undefined) {
            blockObject['minecraft:block']['permutations'] = [];
            blockObject['minecraft:block']['permutations'] =
                blockData.permutations;
        }

        // 生成文件名 - 移除标识符中的冒号及冒号前的部分
        // 例如: "cb:limestone" -> "limestone.json"
        const fileName = blockData.identifier.split(':').pop() + '.json';
        const filePath = `${blocksDir}${fileName}`;

        // 写入文件
        FileUtil.writeFile(filePath, jsonc.stringify(blockObject, null, 4));

        // 将方块的 blocks 属性添加到 this.blocks 对象中
        if (blockData.blocks) {
            // 使用完整的标识符作为键（例如 "cb:limestone"）
            this.blocks[blockData.identifier] = blockData.blocks;
            console.log(`已添加到 blocks.json: ${blockData.identifier}`);
        }

        console.log(`已生成: ${fileName} (${blockData.identifier})`);
    }

    // 写入 blocks.json 文件到资源包
    writeBlocksJson() {
        // 检查是否有方块数据
        if (Object.keys(this.blocks).length <= 1) {
            // 只有 format_version
            console.warn('没有方块数据可写入 blocks.json，跳过');
            return;
        }

        const filePath = `${this.paths.rp}blocks.json`;

        try {
            // 将 blocks 对象转换为格式化的 JSON 字符串
            const blocksJson = jsonc.stringify(this.blocks, null, 4);

            // 写入文件
            FileUtil.writeFile(filePath, blocksJson);

            console.log(
                `成功写入 blocks.json，包含 ${
                    Object.keys(this.blocks).length - 1
                } 个方块定义`
            );
        } catch (error) {
            console.error(`写入 blocks.json 时发生错误: ${error.message}`);
        }
    }

    // 写入方块战利品数据到 block_loot.json
    writeBlockLootDataJson() {
        // 检查是否有方块战利品数据
        if (Object.keys(this.blockLootData).length === 0) {
            console.warn('没有方块战利品数据可写入 block_loot.json，跳过');
            return;
        }

        const configDir = `${this.paths.plugin}`;
        const filePath = `${configDir}block_loot.json`;

        try {
            // 确保config目录存在
            FileUtil.ensureDir(filePath);

            // 将方块战利品数据转换为格式化的 JSON 字符串
            const blockLootDataJson = jsonc.stringify(
                this.blockLootData,
                null,
                4
            );

            // 写入文件
            FileUtil.writeFile(filePath, blockLootDataJson);

            console.log(
                `成功写入 block_loot.json，包含 ${
                    Object.keys(this.blockLootData).length
                } 个矿石定义`
            );

            // 输出详细的方块战利品数据信息
            Object.keys(this.blockLootData).forEach((oreId) => {
                const data = this.blockLootData[oreId];
                console.log(
                    `  - ${oreId}: 挖掘等级=${data.dig_level}, 掉落=${data.drop_item} x${data.drop_count}`
                );
            });
        } catch (error) {
            console.error(`写入 block_loot.json 时发生错误: ${error.message}`);
        }
    }
}

// 矿类地物生成器类
class OreFeatureGenerator {
    constructor(configManager) {
        this.cfg = configManager.config; // 主配置
        this.oreFeatureConfig = configManager.ore_feature; // 矿类地物配置文件内容
        this.paths = configManager.paths; // 路径配置

        // 矿类地物模板对象
        this.oreFeatureTemplate = {
            format_version: '1.13.0',
            'minecraft:ore_feature': {
                description: {
                    identifier: '',
                },
                count: 0,
                replace_rules: [],
            },
        };

        // 矿类地物规则模板对象
        this.oreFeatureRuleTemplate = {
            format_version: '1.13.0',
            'minecraft:feature_rules': {
                description: {
                    identifier: '',
                    places_feature: '',
                },
                conditions: {
                    placement_pass: '',
                    'minecraft:biome_filter': [],
                },
                distribution: {
                    iterations: 0,
                    coordinate_eval_order: 'zyx',
                    x: {
                        distribution: 'uniform',
                        extent: [0, 16],
                    },
                    y: {
                        distribution: 'uniform',
                        extent: [0, 16],
                    },
                    z: {
                        distribution: 'uniform',
                        extent: [0, 16],
                    },
                },
            },
        };
    }

    // 生成矿类地物文件
    generateOreFeatureFiles() {
        console.log('开始生成矿类地物文件...');

        // 检查是否有矿类地物配置
        if (
            !this.oreFeatureConfig ||
            !this.oreFeatureConfig.blocks ||
            !Array.isArray(this.oreFeatureConfig.blocks)
        ) {
            console.warn('没有找到矿类地物配置，跳过矿类地物文件生成');
            return;
        }

        // 确保features和feature_rules目录存在
        const featuresDir = `${this.paths.bp}features/`;
        const featureRulesDir = `${this.paths.bp}feature_rules/`;
        FileUtil.ensureDir(`${featuresDir}dummy.json`);
        FileUtil.ensureDir(`${featureRulesDir}dummy.json`);

        // 遍历矿类地物配置数组
        this.oreFeatureConfig.blocks.forEach((oreData, index) => {
            this.generateSingleOreFeature(
                featuresDir,
                featureRulesDir,
                oreData,
                index
            );
        });

        console.log(
            `成功生成 ${this.oreFeatureConfig.blocks.length * 2} 个矿类地物文件`
        );
    }

    // 生成单个矿类地物的feature和feature_rule文件
    generateSingleOreFeature(featuresDir, featureRulesDir, oreData, index) {
        // 检查必要的feature_rule和feature数据
        if (!oreData.feature_rule || !oreData.feature) {
            console.warn(
                `跳过第${
                    index + 1
                }个矿类地物配置，缺少feature_rule或feature数据`
            );
            return;
        }

        // 生成feature文件
        if (oreData.feature && oreData.feature.ore_feature) {
            this.generateFeatureFile(featuresDir, oreData.feature.ore_feature);
        }

        // 生成feature_rule文件
        if (oreData.feature_rule) {
            this.generateFeatureRuleFile(featureRulesDir, oreData.feature_rule);
        }
    }

    // 生成feature文件
    generateFeatureFile(featuresDir, featureData) {
        // 检查必要字段
        if (!featureData.identifier) {
            console.warn('跳过缺少identifier的feature配置:', featureData);
            return;
        }

        // 创建feature对象副本
        const featureObject = JSON.parse(
            JSON.stringify(this.oreFeatureTemplate)
        );

        // 设置基本属性
        featureObject['minecraft:ore_feature'].description.identifier =
            featureData.identifier;

        // 设置count
        if (featureData.count !== undefined) {
            featureObject['minecraft:ore_feature'].count = featureData.count;
        }

        // 设置replace_rules
        if (
            featureData.replace_rules &&
            Array.isArray(featureData.replace_rules)
        ) {
            featureObject['minecraft:ore_feature'].replace_rules =
                featureData.replace_rules;
        }

        // 设置discard_chance_on_air_exposure（如果存在）
        if (featureData.discard_chance_on_air_exposure !== undefined) {
            featureObject[
                'minecraft:ore_feature'
            ].discard_chance_on_air_exposure =
                featureData.discard_chance_on_air_exposure;
        }

        // 生成文件名 - 移除标识符中的冒号及冒号前的部分
        // 例如: "cb:limestone" -> "limestone.json"
        const fileName = featureData.identifier.split(':').pop() + '.json';
        const filePath = `${featuresDir}${fileName}`;

        // 写入文件
        FileUtil.writeFile(filePath, jsonc.stringify(featureObject, null, 4));

        console.log(`已生成特征文件: ${fileName} (${featureData.identifier})`);
    }

    // 生成feature_rule文件
    generateFeatureRuleFile(featureRulesDir, featureRuleData) {
        // 检查必要字段
        if (!featureRuleData.identifier) {
            console.warn(
                '跳过缺少identifier的feature_rule配置:',
                featureRuleData
            );
            return;
        }

        // 创建feature_rule对象副本
        const featureRuleObject = JSON.parse(
            JSON.stringify(this.oreFeatureRuleTemplate)
        );

        // 设置基本属性
        featureRuleObject['minecraft:feature_rules'].description.identifier =
            featureRuleData.identifier;

        // 设置places_feature
        if (featureRuleData.places_feature) {
            featureRuleObject[
                'minecraft:feature_rules'
            ].description.places_feature = featureRuleData.places_feature;
        }

        // 设置placement_pass
        if (featureRuleData.placement_pass) {
            featureRuleObject[
                'minecraft:feature_rules'
            ].conditions.placement_pass = featureRuleData.placement_pass;
        }

        // 设置biome_filter
        if (
            featureRuleData.biome_filter &&
            Array.isArray(featureRuleData.biome_filter)
        ) {
            this.setBiomeFilter(
                featureRuleObject,
                featureRuleData.biome_filter
            );
        }

        // 设置distribution
        if (featureRuleData.distribution) {
            this.setDistribution(
                featureRuleObject,
                featureRuleData.distribution
            );
        }

        // 生成文件名 - 移除标识符中的冒号及冒号前的部分
        // 例如: "cb:limestone" -> "limestone.json"
        const fileName = featureRuleData.identifier.split(':').pop() + '.json';
        const filePath = `${featureRulesDir}${fileName}`;

        // 写入文件
        FileUtil.writeFile(
            filePath,
            jsonc.stringify(featureRuleObject, null, 4)
        );

        console.log(
            `已生成特征规则文件: ${fileName} (${featureRuleData.identifier})`
        );
    }

    // 设置生物群系过滤器
    setBiomeFilter(featureRuleObject, biomeFilterArray) {
        // 创建any_of数组，包含所有生物群系条件
        const anyOfConditions = biomeFilterArray.map((biomeName) => ({
            test: 'has_biome_tag',
            operator: '==',
            value: biomeName,
        }));

        // 设置minecraft:biome_filter为一个数组，其中包含一个any_of对象
        featureRuleObject['minecraft:feature_rules'].conditions[
            'minecraft:biome_filter'
        ] = [
            {
                any_of: anyOfConditions,
            },
        ];
    }

    // 设置分布参数
    setDistribution(featureRuleObject, distributionData) {
        const distribution =
            featureRuleObject['minecraft:feature_rules'].distribution;

        // 设置迭代次数
        if (distributionData.iterations !== undefined) {
            distribution.iterations = distributionData.iterations;
        }

        // 设置x轴分布
        if (distributionData.x) {
            distribution.x = {
                ...distribution.x,
                ...distributionData.x,
            };
        }

        // 设置y轴分布
        if (distributionData.y) {
            distribution.y = {
                ...distribution.y,
                ...distributionData.y,
            };
        }

        // 设置z轴分布
        if (distributionData.z) {
            distribution.z = {
                ...distribution.z,
                ...distributionData.z,
            };
        }

        // 设置散射几率（如果存在）
        if (distributionData.scatter_chance) {
            distribution.scatter_chance = distributionData.scatter_chance;
        }
    }
}

// 文件操作工具类 - 提供通用的文件操作方法
class FileUtil {
    // 写入文件，自动创建目录
    static writeFile(path, data) {
        this.ensureDir(path);
        fs.writeFileSync(path, data);
    }

    // 读取文件
    static readFile(path) {
        return fs.readFileSync(path, 'utf8');
    }

    // 确保目录存在，不存在则创建
    static ensureDir(path) {
        const dir = path.substring(0, path.lastIndexOf('/'));
        fs.mkdirSync(dir, { recursive: true });
    }

    // 复制整个文件夹
    static copyFolder(source, destination) {
        fs.cpSync(source, destination, { recursive: true });
    }

    // 创建空的contents.json文件
    static createContentsFile(path) {
        this.writeFile(`${path}contents.json`, '{}');
    }
}

// 主应用程序类 - 协调所有构建过程
class AddonBuilder {
    constructor() {
        // 初始化所有组件
        this.config = new ConfigManager(); // 配置管理
        this.manifestGen = new ManifestGenerator(this.config); // 清单生成
        this.textureGen = new TextureIndexGenerator(this.config); // 纹理索引生成
        this.blockGen = new BlockGenerator(this.config); // 方块生成
        this.oreFeatureGen = new OreFeatureGenerator(this.config); // 矿类地物生成
    }

    // 运行构建过程
    run() {
        console.log('开始构建附加包...');

        // 1. 生成清单文件
        this.manifestGen.generateBP();
        this.manifestGen.generateRP();

        // 2. 创建目录文件
        FileUtil.createContentsFile(this.config.paths.bp);
        FileUtil.createContentsFile(this.config.paths.rp);

        // 3. 生成纹理索引
        this.textureGen.generateItemTextureIndex();
        this.textureGen.generateTerrainTextureIndex();

        // 4. 生成方块注册文件
        this.blockGen.generateBlockFiles();

        // 5. 生成矿类地物注册文件
        this.oreFeatureGen.generateOreFeatureFiles();

        console.log('附加包构建完成！');
    }
}

// 启动构建器
try {
    const builder = new AddonBuilder();
    builder.run();
} catch (error) {
    console.error('构建过程中发生错误:', error);
    process.exit(1); // 发生错误时退出程序
}
