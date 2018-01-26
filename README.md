# Hello DirectX12 Program

[Microsoft/DirectX-Graphics-Samples](https://github.com/Microsoft/DirectX-Graphics-Samples)

のサンプル中の "Hello Window Sample" をCMakeでビルド

## ビルド

VS2015 x64 Native Tools Command Promptより

### MSBuild

```
> mkdir build
> cd build
> cmake -G "Visual Studio 14 2015 Win64" ..
> msbuild HelloDX12.sln /m:9
```

### Ninja

```
> mkdir build
> cd build
> cmake -G "Ninja" -DCMAKE_C_COMPILER=cl -DCMAKE_CXX_COMPILER=cl ..
> ninja -j9
```