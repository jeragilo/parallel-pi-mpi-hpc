![Language](https://img.shields.io/badge/C++-MPI-orange)
![Platform](https://img.shields.io/badge/Tested-on%20Bridges2-blue)
![License](https://img.shields.io/badge/license-MIT-green)
![Status](https://img.shields.io/badge/project-complete-brightgreen)
# Parallel Pi Approximation with MPI 🧠💻

This project implements a high-performance parallel approximation of π using the midpoint rule and MPI. It was benchmarked on the Bridges2 supercomputer using SLURM with 1, 12, 24, and 48 cores.

## 📌 Key Features
- ✅ 4 implementations: `pi1.cpp` through `pi4.cpp`
- ✅ Uses `MPI_Reduce` and `MPI_Bcast`
- ✅ Includes SLURM scripts to run on HPC clusters
- ✅ Full report analyzing performance, speedup, and scaling behavior

## 🖥️ Technologies Used
- C++
- OpenMPI
- SLURM
- HPC (Bridges2 @ Pittsburgh Supercomputing Center)

## 📊 Performance Summary

| Cores | Time (s) | Speedup | Efficiency (%) |
|-------|----------|---------|----------------|
| 1     | 3.50     | 1.00    | 100.0          |
| 12    | 0.345    | 10.14   | 84.5           |
| 24    | 0.346    | 10.12   | 42.1           |
| 48    | 3.50     | 1.00    | 2.0            |

## 📎 Files Included
- `pi1.cpp` to `pi4.cpp`: Four stages of parallel implementation
- SLURM job scripts: `job-pi2-01.slurm`, etc.
- `report.txt`: Final project report with results and analysis

##folder Structure
```
parallel-pi-mpi-hpc/
├── src/
│   ├── pi1.cpp
│   ├── pi2.cpp
│   ├── pi3.cpp
│   └── pi4.cpp
├── jobs/
│   ├── job-pi2-01.slurm
│   ├── job-pi2-12.slurm
│   ├── job-pi2-24.slurm
│   └── job-pi2-48.slurm
├── results/
│   └── timing-analysis.csv    ← (optional)
├── report.txt
├── README.md
└── LICENSE
```
## 📘 What I Learned
- Writing MPI programs in C++
- Measuring parallel performance and speedup
- SLURM job submission and HPC benchmarking
- Communication overhead and scalability limits

## 📌 Author
**Jesús Gil**  
M.S. Computer Science  
[LinkedIn](https://www.linkedin.com/in/jesusgil) • [GitHub](https://github.com/jeragilo)


