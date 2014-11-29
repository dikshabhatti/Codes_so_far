Multilevel feedback queue (MLFQ) scheduling has been implemented here
-It allows a process to move between the several queues. 
-Here, a time quantum (decided upon CPU burst time) is used to schedule the
 processes.

Pseudo Code 
1. Input number of processes n.
2. While I = 1 to n
3. Enter the PID, Priority, PAT and PBT
4. Push each process into different process type list based on their priority.
5. Make three queues of different size .
6. While completed < n
7. Assign time quanta for each queue
8. switch counter
9. for counter = 0 to 3
10. fill in queue 1
11. execute in queue 1
12.for counter = 4 to 5
13. fill in queue 2
14. execute in queue
15.if counter = 6
16. fill in queue 3
17. execute in queue 3
18.updating the processes list.
19.If processes
20. Print average waiting time and average turn waiting time.
