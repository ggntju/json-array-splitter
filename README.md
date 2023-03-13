# Welcome to JSON Array Splitter

## Getting Started

### Overview

_JSON Array Splitter_ is a JSON data processing tool for splitting an extremely huge JSON array data file (which you can not load to your memory) into multiple smaller pieces and in the meanwhile, the splitted data piece still keeps the original JSON array data format. 

## How to Use

### Data Schema

_JSON Array Splitter_ can deal with JSON array file with the following data schema. 

```
[
    {JSON Object 1},
    ...
    ...
    {JSON Object N}
]
```

See [good.json](./examples/good.json) for more detailed example.

### Compile

Suppose you are in the root folder, run
```
mkdir build && cd build && cmake ..
```
Then
```
make
```

### Usage

Suppose you are in the build folder, run
```
./JSON-ARRAY-SPLITTER [file_path] [lines_per_file]
```
It only takes two arguments as parameters, the first one is the path to your input file, the second one is number of lines of data you would like to keep in your splitted file. 

The output files stay in the same folder as your binary, named with a _part_XXX_ pattern. 

### Dependencies

 - Build Management: [CMake](https://cmake.org/)

 - JSON: [nlohmann/json](https://github.com/nlohmann/json)

 - C++ Standard: C++17
 
 - 
