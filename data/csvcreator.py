with open("data/sample.csv", "w") as csvfile:
    csvfile.writelines(",".join([f"head{i:02d}" for i in range(1, 6)]) + "\n")
    for i in range(1, 10):
        csvfile.writelines(
            ",".join([f"cell{i}{j}" for j in range(1, 6)]) + "\n")
