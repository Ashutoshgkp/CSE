# TCP-like Functionalities over UDP

## Overview

This project implements TCP-like functionalities over UDP to ensure reliable data transfer between a sender and receiver. UDP, a connectionless protocol, does not guarantee the delivery or order of packets. To address this, we have implemented several mechanisms typically associated with TCP, such as acknowledgments, sequence numbers, retransmissions, congestion control, and flow control.

## Features

- **Acknowledgment Mechanism**: Implements both single-packet and cumulative acknowledgments.
- **Sequence Numbers**: Ensures packets are delivered in the correct order.
- **Retransmission**: Lost packets are retransmitted to ensure reliable delivery.
- **Duplicate Detection**: Detects and discards duplicate packets.
- **Congestion Control**: Adapts to network congestion to avoid overwhelming the network.
- **Flow Control**: Manages the rate of data transmission between sender and receiver.

## Project Structure

- **Sender.c**: Implements the UDP client responsible for sending data packets to the receiver.
- **Receiver.c**: Implements the UDP server that receives data packets from the sender and sends acknowledgments.

## How It Works

1. **Sender Initialization**:
    - The sender initializes with a default server address, port, and other parameters like packet size and window size.
    - Data to be sent is divided into packets, and sequence numbers are assigned.
    
2. **Packet Transmission**:
    - The sender transmits packets to the receiver and starts a timer for each packet.
    - The sender waits for acknowledgments from the receiver before sending new packets.

3. **Receiver Operation**:
    - The receiver listens for incoming packets, decodes the sequence numbers, and checks for missing packets.
    - It sends acknowledgments back to the sender, either acknowledging individual packets or cumulatively.

4. **Retransmission**:
    - If a timeout occurs (indicating a lost packet), the sender retransmits the packet and adjusts the window size according to TCP-like congestion control mechanisms.

## Usage

1. **Compile the Code**:
   ```bash
   gcc -o sender Sender.c
   gcc -o receiver Receiver.c
   ```

2. **Run the Receiver**:
   ```bash
   ./receiver
   ```

3. **Run the Sender**:
   ```bash
   ./sender <receiver_ip> <port> <loss_flag>
   ```

   - `receiver_ip`: IP address of the receiver.
   - `port`: Port number on which the receiver is listening.
   - `loss_flag`: Set to `1` to simulate packet loss, `0` otherwise.

## Results & Observations

- **Reliable Data Transfer**: The system ensures that all data is transmitted and acknowledged correctly.
- **Packet Loss Handling**: The system can handle and recover from packet loss scenarios.
- **Window Size Adaptation**: The sender adjusts the window size dynamically based on network conditions.
- **Performance Metrics**: The system's throughput, latency, and reliability were tested under varying conditions.

## Limitations

- **Fixed Parameters**: The current implementation uses fixed packet and window sizes.
- **Limited Congestion Control**: The system lacks advanced congestion control mechanisms.
- **Scalability**: The system may face challenges in high-congestion or large data size scenarios.

## Future Work

- **Advanced Congestion Control**: Implement more sophisticated congestion control strategies.
- **Dynamic Parameter Adjustment**: Allow dynamic adjustment of packet and window sizes based on network conditions.
- **Selective Acknowledgment**: Explore implementing selective acknowledgment mechanisms for better error recovery.

## Contributors

- Arman Malik
- Ashutosh Mishra
- Rahul Ranjan Mishra

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

