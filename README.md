# Mr_Flamingo

Entry for the Computer Graphics Final Image competition at University of Toronto. I thought it would be fun to make a 3D model of a Flamingo (Mr. Flamingo) using `Blender` and render an image with him using `raytracing` techniques. This rendering uses the (Blinn-Phong shading model] (https://en.wikipedia.org/wiki/Blinn–Phong_reflection_model) to model Lambertian (diffuse) reflectance and specular light (shiny objects). Additionally, I have also incorporated `reflection` and `refraction` of rays hitting Mr. Flamingo and the amazing beach he's chilling at.

## How to run

In order to compile and run the raytracing algorithm to generate the image, perform the following steps:

### Compile

```BASH
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
```

Run `make` if you are on `Mac` or `Linux`

### Run

```BASH
./raytracing
```
