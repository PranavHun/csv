with open("data/sample.csv", "w") as csvfile:
    csvfile.writelines(",".join([f"head{i:d}" for i in range(1, 200)]) + "\n")
    for i in range(1, 6000):
        csvfile.writelines(
            ",".join([f"cell{i}{j}" for j in range(1, 2000)]) + "\n")
