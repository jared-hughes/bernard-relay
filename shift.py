usage = lambda s: "".join([chr(c) if chr(c) in s else " " for c in range(32, 127)])
shift = lambda s, k: "".join([chr(ord(c) + k) for c in s])
