# Ropes
Made by *Jerry Spice*

## What is this?
I am currently taking a school course about using C and learning the C language. I hate working with files and strings because there seem to be several layers of parsing I need to do to avoid having too much or too little memory. I heard about ropes online, which seemed a more straightforward way to prevent my frustration with strings and files.

I made this to avoid these problems and to practice code and library writing. Feel free to use this code and do whatever you would like.


## Basic Structure
```
struct Rope {
    char content[100]; // This can just be any content. I just chose strings because I'm using this specifically for reading files
    struct Rope* nextLink; // linked list moment
};
```
## Functions

```
Rope* createRope(); // This allocates the memory and gives you the pointer
```

```
void destroyRope(Rope* target); // Frees the pointer for our rope
```

```
Rope* fileToRope(char* filename); // Quick and fast for me. Takes a filename, reads it, and turns it into a linked list of ropes
```

```
void ropeToFile(char* filename, Rope* root); // takes as linked list of ropes and writes the output to a file
```
