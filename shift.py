usage = lambda s: "".join([chr(c) if chr(c) in s else " " for c in range(32, 127)])
shift = lambda s, k: "".join([chr(ord(c) + k) for c in s])
with open("bernard-relay-dev.c", "r") as f:
    lines = f.readlines()
with open("out/relay.c~", "w") as f:
    f.writelines(lines)
with open("bernard-relay-dev.c", "w") as f:
    f.writelines(['char*s="' + shift(lines[1][:-1], -2) + '"\n', lines[1]])
