add_rules("mode.debug", "mode.release")



add_repositories("liteldev-repo https://github.com/LiteLDev/xmake-repo.git")
add_repositories("groupmountain-repo https://github.com/GroupMountain/xmake-repo.git")
add_repositories("miracleforest-repo https://github.com/MiracleForest/xmake-repo.git")


add_requires("levilamina 1.9.7", {configs = {target_type = "server"}})
add_requires("levibuildscript 0.6.0")
add_requires("gmlib 1.9.1")
add_requires("ilistenattentively 0.11.3")
add_requires("modapi 0.4.0")

if not has_config("vs_runtime") then
    set_runtimes("MD")
end

option("target_type")
    set_default("server")
    set_showmenu(true)
    set_values("server", "client")
option_end()

target("CBWMod")
    add_rules("@levibuildscript/linkrule")
    add_rules("@levibuildscript/modpacker")
    add_cxflags(
        "/EHa",
        "/utf-8",
        "/W4",
        "/w44265",
        "/w44289",
        "/w44296",
        "/w45263",
        "/w44738",
        "/w45204"
    )
    add_defines(
        "NOMINMAX",
        "UNICODE",
        "_HAS_CXX23=1"
    )
    add_packages(
        "levilamina",
        "gmlib",
        "ilistenattentively",
        "modapi"
    )
    set_optimize("aggressive")
    set_exceptions("none")
    set_kind("shared")
    set_languages("c++20")
    set_symbols("debug")
    add_headerfiles("src/**.h")
    add_files("src/**.cpp")
    add_includedirs("src")
    if is_config("target_type", "server") then
        add_defines("LL_PLAT_S")
    else
        add_defines("LL_PLAT_C")
    end
    after_build(function (target) 
        local config_path = path.join(os.projectdir(), "bin", target:name(), "config")
        os.rm(config_path)
        os.cp(path.join(os.projectdir(), "config"), config_path)
    end)