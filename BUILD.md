# Compile Instructions
### Currently you may use MinGW or Visual Studio to compile this application.

## MinGW-w64 on Command Line / .bat

Assuming you have MinGW's bin folder defined on PATH.
Do not forget that RRE3D's main cannot be ommited.

```cmd
g++ -std=c++17 source/RRE3D/*.cpp source/*.cpp -I include -L lib -l glfw3 -l gdi32 -l opengl32 -o bin/Application.exe
```

## MinGW-w64 args for VSCode tasks.json

```json
"args": [
	"-std=c++17",
	"${workspaceFolder}\\source\\RRE3D\\*.cpp",
	"${workspaceFolder}\\source\\*.cpp",
	"-I${workspaceFolder}\\include",
	"-L${workspaceFolder}\\lib",
	"-lglfw3",
	"-lgdi32",
	"-lopengl32",
	"-o",
    "${workspaceFolder}\\bin\\Application.exe"
]
```

## Visual Studio

Coming Soon