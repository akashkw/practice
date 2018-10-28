tests = int(input())
for t in range(tests):
    input()
    ruth_rocks = sorted(list(map(int, input().split())))
    bleminda_rocks = list(map(int, input().split()))

    def grab_optimal(opponent_rock, ruth_rocks):
        # Grab the minimum greater or else the minimum
        optimal = float('inf')
        for i in range(len(ruth_rocks)):
            if ruth_rocks[i] > opponent_rock:
                optimal = ruth_rocks[i]
                break
        if optimal == float('inf'):
            optimal = ruth_rocks[0]
        ruth_rocks.remove(optimal)
        return optimal

    optimal = list()
    for opponent_rock in bleminda_rocks:
        optimal.append(grab_optimal(opponent_rock, ruth_rocks))

    captured = 0
    for i in range(len(bleminda_rocks)):
        blem = bleminda_rocks[i]
        ruth = optimal[i]
        if ruth <= blem:
            captured += ruth
    
    print(captured)
