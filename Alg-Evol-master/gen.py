import csv
import numpy as np
import matplotlib.pyplot as plt
# centers = []
points = []
# centers.append(np.random.randn(2))
# centers.append(np.random.randn(2) + 2)
# centers.append(np.random.randn(2) + 3)
# centers.append(np.random.randn(2) + 1.5)
# centers.append(np.random.randn(2) + 2.3)

for i in range(300):
    r = np.random.uniform(0.0, 1)
    theta = np.random.uniform(0, 6.28)
    points.append(np.array([r * np.cos(theta), r * np.sin(theta)]))

for i in range(300):
    r = np.random.uniform(0.0, 1.0)
    theta = np.random.uniform(0, 6.28)
    p = np.array([r * np.cos(theta), r * np.sin(theta)])
    u = p/np.linalg.norm(p)
    u *= 2
    points.append(p + u)


print(points[0])
with open("example2.csv", 'w', newline='') as f:
    wr = csv.writer(f)
    wr.writerow([0, 1])
    for i in points:
        wr.writerow(i)


plt.plot([p[0] for p in points], [p[1] for p in points], 'ro')

plt.show()
