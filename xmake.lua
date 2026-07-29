add_rules("mode.debug", "mode.release")

add_repositories("liteldev-repo https://github.com/LiteLDev/xmake-repo.git")
add_repositories("groupmountain-repo https://github.com/GroupMountain/xmake-repo.git")
add_repositories("miracleforest-repo https://github.com/MiracleForest/xmake-repo.git")

option("target_type")
    set_default("server")
    set_showmenu(true)
    set_values("server", "client")
option_end()

add_requires("levilamina 26.20.5", {configs = {target_type = "server"}})
add_requires("levibuildscript")

add_requires("gmlib 26.20.1")
add_requires("modapi 26.20.0")
add_requires("ilistenattentively 0.13.0")

if not has_config("vs_runtime") then
    set_runtimes("MD")
end

target("CBWMod")
    add_rules("@levibuildscript/linkrule")
    add_rules("@levibuildscript/modpacker")
    if is_plat("windows") then
        add_defines("NOMINMAX", "UNICODE")
        set_exceptions("none")
        add_cxflags( "/EHa", "/utf-8", "/W4", "/w44265", "/w44289", "/w44296", "/w45263", "/w44738", "/w45204")
        add_cxflags(
            "/EHs",
            "-Wno-microsoft-cast",
            "-Wno-invalid-offsetof",
            "-Wno-c++2b-extensions",
            "-Wno-microsoft-include",
            "-Wno-overloaded-virtual",
            "-Wno-ignored-qualifiers",
            "-Wno-missing-field-initializers",
            "-Wno-potentially-evaluated-expression",
            "-Wno-pragma-system-header-outside-header",
            {tools = {"clang_cl"}}
        )
        set_toolchains("clang-cl")
    end
    if is_windows then
        add_defines("_HAS_CXX23=1")
    else
        add_defines("_LIBCPP_STD_VER=23")
        add_cxxflags("clang::-stdlib=libc++")
    end
    add_packages(
        "levilamina",
        "levibuildscript",
        "gmlib",
        "ilistenattentively",
        "modapi"
    )
    set_optimize("aggressive")
    set_kind("shared")
    set_languages("c++20")
    set_symbols("debug")
    add_headerfiles("src/**.h")
    add_files("src/**.cpp")
    add_includedirs(
        "sdk/GMLIB/26.20.1/shared/include",
        "sdk/GMLIB/26.20.1/static/include",
        "sdk/iListenAttentively/0.13.0/include",
        "sdk/ModAPI/26.20.0/include",
        "src"
    )
    add_links(
        "sdk/GMLIB/26.20.1/static/lib/GMLIB.lib",
        "sdk/GMLIB/26.20.1/shared/lib/GMLIB.lib",
        "sdk/iListenAttentively/0.13.0/lib/iListenAttentively.lib",
        "sdk/ModAPI/26.20.0/lib/ModAPI.lib"
    )
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