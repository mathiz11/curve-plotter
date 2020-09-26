# Curve Plotter in C++

I made this project in 2019 during my studies.

I needed to create curve plotter in C++ with a GUI.

The program allows you to draw a function that can be either parametric or cartesian. The function is written in reverse Polynesian :

**Example:** f(x) = sin(x) / x is written like this :

```
(/
    (S (X))
    (X)
)
```

This configuration is written on a file that must be specified in parameter of the program.

The first line is function name.
The second line is the function type (it can be "parametric" or "cartesian" only).
And the function

fichier1.txt

```
sin(x)/x
cartesian
-11 11 100
(/
    (S (X))
    (X)
)
```

This project use a small library called [EZ-Draw++](http://eric.remy3.free.fr/EZ-Draw++/EZ-Draw++-1.2-3/html/index.html) created by my profesor for the graphic user interface.

## Installation

You need to have installed "g++" to compile project and "make" to build project.

### Windows

To launch the project, I use [chocolatey](https://chocolatey.org/)

To install you need to launch this command on your PowerShell in admin mode :

```powershell
chocolatey install mingw
chocolatey install make
```

Go to windows folder in the project and launch this :

```powershell
make
```

### Linux

To install you need to launch this command on your terminal :

```bash
sudo apt install build-essential
sudo apt install make
```

Go to unix folder in the project and launch this :

```bash
make
```

## Usage

You need to open a terminal and go to folder where contains the script.
You can create your own configuration file

### Windows

```powershell
main.exe fichier1.txt
```

### Linux

```bash
./main fichier1.txt
```
