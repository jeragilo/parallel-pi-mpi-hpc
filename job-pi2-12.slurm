#!/bin/bash
#SBATCH --job-name=pi2_12
#SBATCH --output=pi2_12_%j.out
#SBATCH --ntasks=12
#SBATCH --time=00:02:00
#SBATCH --partition=RM

module load openmpi
srun ./pi2 100000000

