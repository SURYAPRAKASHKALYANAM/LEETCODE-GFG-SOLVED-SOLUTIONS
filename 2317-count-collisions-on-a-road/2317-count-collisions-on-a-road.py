class Solution:
    def countCollisions(self, directions: str) -> int:
        directions = directions.lstrip("L")
        directions = directions.rstrip("R")
        directions = directions.replace("S", "")
        return len(directions)
