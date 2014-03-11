import random

#id, content, price
data = [(i+1, random.randint(1, 10), random.randint(115, 284)) for i in range(10)]
size = 50

print data
new_data = []
for d in data:
    l = d[2]/d[1]
    for i in range(d[1]):
        new_data.append((d[0], l,))

new_data = sorted(new_data, key=lambda x: x[1], reverse=True)

box = {}
total_price = 0
total_size = size if size > len(new_data) else len(new_data)
for i in range(total_size):
    _id, price = new_data[i]
    if _id not in box.keys():
        box[_id] = 0
    box[_id] += 1
    print price, _id
    total_price += price

print box
