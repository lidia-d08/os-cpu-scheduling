This repository contains a collection of Operating system algorithms implemented in c++.It includes various CPU scheduling strategies and the Bankers Algorithm for deadlock avoidance.We implemented four key CPU scheduling algorithms to compare their efficiency in terms of Average Waiting Time (AWT) and Average Turnaround Time (ATAT):
​-FCFS provided the simplest logic but suffered from the "Convoy Effect" when a long process arrived first.
​-SJF and SRTF were significantly more efficient for the provided test data, as they prioritized shorter tasks to reduce the overall wait time.
​-Round Robin proved to be the most "fair" algorithm for time-sharing systems, though its efficiency depended heavily on the chosen Time Quantum (TQ=2).
​-The Banker's Algorithm was successfully implemented to simulate resource management. It correctly identifies whether a system is in a Safe State by calculating the "Need Matrix" and checking if available resources can satisfy at least one process's maximum requirements to complete a safe sequence.And it have like this file structure:
os-cpu-scheduling/
│
├── README.md
├── src/
├── input/
├── output/
└── screenshots
Group members
             Name                                             ID number

          1.  LIDIA  DESALEGN...............BDU1601923
           2.  MAEREG ARKSIE................BDU1601944
           3.  MEKDES ABIY.......................BDU1512703
           4   MELKAM  DEMELASH..........BDU1602051
           5.  Mulualem Ayehu.................BDU1706747
          6.   NEBYU  ESUBALEW..............BDU1602265
         7 .  OMEGA CHALACHEW...........BDU1602296
         8.  RAHEL AMARE.....................BDU1602304
<img width="1136" height="943" alt="image" src="https://github.com/user-attachments/assets/0f122f08-e175-41f7-b7c3-bc6408344c38" />

