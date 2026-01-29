#!/bin/bash
#SBATCH --job-name=pi2_24
#SBATCH --output=pi2_24_%j.out
#SBATCH --ntasks=24
#SBATCH --time=00:02:00
#SBATCH --partition=RM

module load openmpi
srun ./pi2 100000000

