workspace "Rorschach"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"	
	
project "Rorschach"
	location "Rorschach"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"RSC_PLATFORM_WINDOWS",
			"RSC_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin//" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "RSC_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "RSC_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "RSC_DIST"
		optimize "On"
	
	
	
project "SandboxProj"
	location "SandboxProj"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"Rorschach/src"
	}
	
	links
	{
		"Rorschach"
	}
	
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"RSC_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "RSC_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "RSC_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "RSC_DIST"
		optimize "On"