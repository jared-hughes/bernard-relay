usage = lambda s: "".join([chr(c) if chr(c) in s else " " for c in range(32, 127)])
shift = lambda s, k: "".join([chr(ord(c) + k) for c in s])
with open("bernard-relay.c", "r") as f:
    lines = f.readlines()
    print(lines)
with open("out/relay.c~", "w") as f:
    f.writelines(lines)
with open("bernard-relay.c", "w") as f:
    print(lines)
    f.writelines(['char*s="' + shift(lines[1][:-1], -2) + '"\n', lines[1]])
