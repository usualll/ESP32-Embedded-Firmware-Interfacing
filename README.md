# Embedded Systems: ESP32 Sensor Interfacing & Signal Acquisition

## Technical Overview
This repository contains the bare-metal embedded C++ firmware developed to interface an ESP32 microcontroller with an HC-SR04 ultrasonic transducer. The project demonstrates low-level peripheral configuration, hardware timing analysis, and real-time sensor data parsing.

Establishing competency in bare-metal microcontroller firmware bridges the gap between high-level logic design (Verilog/HDL) and the physical silicon level, establishing a complete full-stack hardware engineering profile.

## Engineering Competencies
* **Microcontroller Architecture:** Peripheral register mapping and GPIO configuration on the ESP32 platform.
* **Signal Interfacing & Timing:** Microsecond-precision pulse generation and Time-of-Flight (ToF) capture logic using hardware timers.
* **Software Environment:** Embedded C++ scripting, data serialization, and UART Serial communication handling (115200 baud).
* **Virtual Prototyping:** Circuit schematics layout and physical simulation using the Wokwi embedded workbench.

## Firmware Logic & Mathematical Calculation
The firmware operates a tight, optimized timing loop. The microcontroller triggers the transducer with a clean 10-microsecond pulse to initiate acoustic wave emission. The echo pin duration is captured in microseconds and converted to a physical displacement vector using the kinematics of sound propagation in air:

$$\text{Distance (cm)} = \frac{\text{Duration }(\mu\text{s}) \times 0.0343\text{ cm/}\mu\text{s}}{2}$$

The factor of 2 accounts for the bidirectional path (round-trip) of the acoustic pulse.

### Live Simulation Setup
*(The visual capture below confirms stable execution of the time-of-flight mathematical parser, outputting real-time, human-readable telemetry data via the UART link).*

<img width="686" height="797" alt="ros" src="https://github.com/user-attachments/assets/355b0eca-fcc2-47cd-bd29-1ddabf11462b" />
<img width="950" height="795" alt="184" src="https://github.com/user-attachments/assets/35047eef-000b-4ab7-b713-25ef34c3fa7e" />
<img width="958" height="802" alt="326" src="https://github.com/user-attachments/assets/120f0103-9afc-4700-baa1-368adc9ada2f" />


## Repository Structure
* `/sketch.ino`: Main firmware application containing peripheral initializations and execution control loops.
* `/simulation_proof.png`: High-resolution functional validation schematic and terminal telemetry.
