#!/usr/bin/env python3
import random
import subprocess

for n in range(1, 20):
  for t in range(50):
    l = [random.randrange(-100, 100) for _ in range(n)]
    args = " ".join(f"{x}" for x in l)
    r = subprocess.run(f"./push_swap {args} | ./checker_Mac {args}", shell=True, capture_output=True)
    if r.stdout == b"KO\n":
      print(args)
