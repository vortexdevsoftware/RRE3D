# Compile Instructions
### Currently you may use MinGW or Visual Studio to compile this application.

## Mingw-w64 args for VSCode tasks.json

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