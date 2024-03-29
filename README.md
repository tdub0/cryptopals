# cryptopals crypto challenges

## Overview

A personal walkthrough of [the cryptopals crypto challenges](https://cryptopals.com/), which are meant to provide a different way to learn about cryptography. 

## Usage

To build and test locally, run the following commands:
```
cmake -B build
cmake --build build
cd build && ctest
```

## Format

To run `clang-format` on the project files, run the following command:
```
find include/ src/ test/ -name *.hpp -o -name *.cpp | xargs clang-format -i
```

## Credit

Thanks are in order for Thomas Ptacek, Sean Devlin, Alex Balducci, and Marcin Wielgoszewski for their work on [the cryptopals crypto challenges](https://cryptopals.com/).

## License

This project is licensed under the MIT license. Please see the [LICENSE](LICENSE) file for more details.
