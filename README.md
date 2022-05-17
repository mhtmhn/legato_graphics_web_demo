

# Legato Graphics Web Demo

POC of a web browser based simulator for Microchip's graphics library.

# Setup

> For Windows only, skip this if you are running Linux
> 
> Go to step "Refresh package cache"

**Install WSL 2**

    https://aka.ms/wslinstall

Enable Virtualization in the BIOS, if not already enabled.

Start (search) -> Turn Windows features on or off -> Enable/Tick Hyper-V (All features)

Restart PC

**Install and run Ubuntu**

    https://www.microsoft.com/store/productId/9PDXGNCFSCZV

> Add username and password when prompted and wait for the shell.

**Refresh package cache**

    sudo apt update

**Install SDL**

    sudo apt-get install libsdl2-2.0-0 libsdl2-dev

**Install Essentials**

    sudo apt-get install build-essential git python3 cmake

**Install Emscripten SDK**

    mkdir tools
    cd tools
    git clone https://github.com/emscripten-core/emsdk.git
    cd emsdk
    ./emsdk install latest
    ./emsdk activate latest

**Add Emscripten SDK to PATH**

Permanently add to PATH (recommended)

> Note, this command appears as a hint in the output of the previous
> command. The path below is only for e.g. (the actual path may vary
> based on username).

    echo 'source "/home/<username>/tools/emsdk/emsdk_env.sh"' >> $HOME/.bash_profile

Activate bash profile without restarting shell and return to home directory.

    source ~/.bash_profile
    cd ~
Or, you can setup the environment manually every time shell is restarted. 
> Not required if you performed the previous step.

    . <emsdk_path>/emsdk_env.sh


# Building

**Clone the repo**

    git clone https://github.com/mhtmhn/legato_graphics_web_demo.git

**Create a build folder**

    cd legato_graphics_web_demo/src/legato_display_sim
    mkdir build
    cd build

**Run CMake**

> Note, you need to run `. <emsdk_path>/emsdk_env.sh` first, if you haven't added Emscripten SDK to PATH

     emcmake cmake ..

**Run Make**

> You can use -j<number_of_logical_cpu_cores> depending on your hardware

    emmake make -j4

**Launch the web page**

> Tested on Ubuntu 20.04 w/ WSL2

    sensible-browser legato_display_sim.html


# Typical Output
![typical_output](https://user-images.githubusercontent.com/14132871/168876400-13533d5b-7d4b-4c57-b063-cede48444783.png)
