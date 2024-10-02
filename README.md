# Maximum Power Point Tracking (MPPT) for Photovoltaic (PV) Systems

This repository contains simulation models, MATLAB code, and hardware implementation code for Maximum Power Point Tracking (MPPT) in Photovoltaic (PV) systems. It serves as additional supporting material for our published paper.

## Repository Structure

The repository is organized into three main folders:

1. Simulink Models
2. MATLAB Code
3. Hardware Code

### 1. Simulink Models

This folder contains Simulink simulation files for MPPT implemented on three different converter topologies:

- Buck Converter
- Boost Converter
- Buck-Boost Converter

These simulations demonstrate the behavior and performance of MPPT algorithms in various converter configurations.

### 2. MATLAB Code

The MATLAB code folder includes implementations of three MPPT algorithms:

- Perturb and Observe (P&O)
- Power Increment
- Constant Voltage

These MATLAB scripts can be used for algorithm testing, data analysis, and performance evaluation.

### 3. Hardware Code

The Hardware Code folder contains Arduino implementations of the same MPPT algorithms:

- Perturb and Observe (P&O)
- Power Increment
- Constant Voltage

These code files are ready to be uploaded to Arduino boards for practical implementation and testing of MPPT algorithms in real PV systems.

## Usage

### Simulink Models

1. Open MATLAB and navigate to the Simulink Models folder.
2. Double-click on the desired `.slx` file to open the Simulink model.
3. Run the simulation and analyze the results.

### MATLAB Code

1. Open MATLAB and set the MATLAB Code folder as your working directory.
2. Run the desired MPPT algorithm script (e.g., `perturb_and_observe.m`).
3. Follow any on-screen instructions for input parameters or data visualization.

### Hardware Code

1. Open the Arduino IDE.
2. Load the desired MPPT algorithm file from the Hardware Code folder.
3. Connect your Arduino board and upload the code.
4. Follow the specific hardware setup instructions provided in the paper or comments within the code.

## Requirements

- MATLAB (version R2018b or higher) with Simulink
- Arduino IDE (for hardware implementation)
- Arduino board (e.g., Arduino Uno, Arduino Mega)

## Citation

If you use this code or data in your research, please cite our paper:

```
[Author Names]. (Year). [Paper Title]. [Journal Name], [Volume](Issue), [Page range]. [DOI]
```
