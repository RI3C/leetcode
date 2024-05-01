class StockPrice {
public:
    map<int,int> stockPrice;
    map<int,int> priceCount;
    int maxPrice, minPrice; 
    StockPrice() {
        maxPrice=0;
        minPrice=INT_MAX;
    }
    
    void update(int timestamp, int price) {
        priceCount[price]++;
        auto it=stockPrice.find(timestamp);
        if(it!=stockPrice.end()) priceCount[it->second]--;
        if(priceCount[it->second]<=0) priceCount.erase(it->second);
        stockPrice[timestamp]=price;
    }
    
    int current() {
        auto lastPair = prev(stockPrice.end());
        return lastPair->second; 
    }
    
    int maximum() {
         return prev(priceCount.end())->first;
    }
    
    int minimum() {
        return priceCount.begin()->first;
      
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */