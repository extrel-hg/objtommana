# Overview
objtommana is a simple script that converts Blender-generated[^1] .obj files to .maa save files.

# Usage
As of right now, there is only a Windows executable provided.

## Blender export and design

Design your antenna in Blender. The scale between the two programs is 1:1, although orientation is not guaranteed[^2] to be preserved. Make sure there is only the antenna object in your Blender file, and that it is compromised of only edges and vertices, faces will not work at all![^3] To quickly delete faces, go into edit mode, select the whole object, press "X" then select "Only Faces".

Export your project as an .obj file.

## Usage of the executable

Make sure to put the .obj file in the same directory as the .exe.

Open the .exe file either by double-clicking it, or through the terminal. Input the name of the .obj file (without the .obj suffix). The program will then convert the file, and save the result as "result.maa", which can be opened by MMANA.

## Notes

The program only converts the wire geometry, loads and sources have to be added in MMANA.

[^1]: .obj files from other sources are not guaranteed to work.
[^2]: To be fixed.
[^3]: To be fixed.