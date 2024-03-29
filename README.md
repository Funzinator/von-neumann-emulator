# von-Neumann-Emulator

![Windows-Build](https://img.shields.io/appveyor/job/build/Funzinator/von-neumann-emulator/Image%3A%20Visual%20Studio%202019/master?label=Windows)
![macOS-Build](https://img.shields.io/appveyor/job/build/Funzinator/von-neumann-emulator/Image%3A%20macos-monterey/master?label=macOS)
![Linux-Build](https://img.shields.io/appveyor/job/build/Funzinator/von-neumann-emulator/Image%3A%20Ubuntu2004/master?label=Linux)
![WASM-Build](https://img.shields.io/appveyor/job/build/Funzinator/von-neumann-emulator/Image%3A%20Ubuntu2204/master?label=WASM)

Dieses Programm wurde im Rahmen des Fortgeschrittenen-Praktikums im Wintersemester 2008 an der Justus-Liebig-Universität Gießen entwickelt.

Es emuliert von-Neumann-Instruktionen und erlaubt Debugging der Programme.

## Releases

Unter [Releases](https://github.com/Funzinator/von-neumann-emulator/releases) befinden sich fertig kompilierte Pakete für Windows, macOS und Linux.

Es gibt außerdem eine [Web-Variante](https://funzinator.github.io/von-neumann-emulator/), die in einem aktuellen WASM-fähigen Browser läuft.

## Kompilieren

Zum Kompilieren wird Qt6 oder höher verwendet. Diese Bibliothek muss installiert sein. Dann ist die Kompilierung sehr einfach:

```shell
qmake
make
```

Um die WASM-Variante zu bauen, muss [Qt for WebAssembly](https://doc.qt.io/qt-6/wasm.html) kompiliert werden.
Zur Vereinfachung verwenden wir ein angepasstes [Docker-Image](./Dockerfile).

```shell
docker run --rm \
  -v "$PWD:/home/user/project:rw" \
  -w /home/user/project \
  ghcr.io/funzinator/qt6-wasm:6.6 \
  sh -c 'qmake && make -j $(nproc)'
```
