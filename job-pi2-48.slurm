#!/bin/bash
#SBATCH --job-name=pi2_48
#SBATCH --output=pi2_48_%j.out
#SBATCH --ntasks=48
#SBATCH --time=00:02:00
#SBATCH --partition=RM

module load openmpi
srun ./pi2 100000000

