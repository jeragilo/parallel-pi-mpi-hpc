#!/bin/bash
#SBATCH --job-name=pi2_01
#SBATCH --output=pi2_01_%j.out
#SBATCH --ntasks=1
#SBATCH --time=00:02:00
#SBATCH --partition=RM

module load openmpi
srun ./pi2 100000000

