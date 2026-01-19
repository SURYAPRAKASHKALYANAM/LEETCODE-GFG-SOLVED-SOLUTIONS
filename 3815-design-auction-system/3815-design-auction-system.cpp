class AuctionSystem {
public:
    unordered_map<int, set<pair<int, int>>> itemBids;
    unordered_map<int, unordered_map<int, int>> userBids;
    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {
        if (userBids[userId][itemId]) {
            updateBid(userId, itemId, bidAmount);
        } else {
            userBids[userId][itemId] = bidAmount;
            itemBids[itemId].insert({bidAmount, userId});
        }
    }

    void updateBid(int userId, int itemId, int newAmount) {
        itemBids[itemId].erase({userBids[userId][itemId], userId});
        userBids[userId][itemId] = newAmount;
        itemBids[itemId].insert({newAmount, userId});
    }

    void removeBid(int userId, int itemId) {
        itemBids[itemId].erase({userBids[userId][itemId], userId});
        userBids[userId][itemId] = 0;
    }

    int getHighestBidder(int itemId) {
        return itemBids[itemId].size() ? itemBids[itemId].rbegin()->second : -1;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */