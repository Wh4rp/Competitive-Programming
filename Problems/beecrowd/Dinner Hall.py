n = int(input())

while n != 0:
    events = []
    for i in range(n):
        s, event = input().split(' ')
        time = s.split(":")
        time = 3600 * int(time[0]) + 60 * int(time[1]) + int(time[2])
        if event == "E":
            events.append([time, 1])
        elif event == "?":
            events.append([time, 0])
        else:
            events.append([time, -1])
    events.sort()
    suma = 0
    for element in events:
        if element[1] > -1:
            suma += 1
        else:
            suma -= 1

    for i in range(len(events) - 1, -1, -1):
        if events[i][1] == 0:
            if suma > 0:
                events[i][1] = -1
                suma -= 2
            else:
                events[i][1] = 1
    
    suma = 0
    maxi = 0

    for element in events:
        if element[1] > -1:
            suma += 1
        else:
            suma -= 1
        maxi = max(maxi, suma)

    print(maxi)
    n = int(input())