# Welcome to My Malloc
***

## Task
This project consist on recreating dynamic memory allocation functions as malloc() calloc() realloc() and free(). <br>

## Description
For the porpouse of this project we are using `mmap()`. `mmap()` function establishes a mapping between a process' address space and a stream file. <br>

The program initializates the memory map at the beggining, this being stored into a block of a linked list which acts as the 'heap'. Once the memory map is stored, whenever a memory function is called, the program checks for free blocks of memory with enough space to cover the amount of space the user asks for. If this conditions are meet a new memory block is created with the specifications of the user.

## Installation
No installation is required.
Build with `make`.

## Usage
Execute it like this `./my_malloc`

### The Core Team

Soraia Lima Cid
Michael Mullins


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
