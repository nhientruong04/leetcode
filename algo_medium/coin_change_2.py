class Solution:
    def change(self, amount: int, coins: list[int]) -> int:
        if amount == 0:
            return 1

        dp_coin = [0] * (amount+1)
        dp_coin[0] = 1
        coins = sorted(coins)
             
        for coin in coins:
            for sub_amount in range(1, amount+1):

                residual_amount = sub_amount - coin
                if residual_amount>=0:
                    dp_coin[sub_amount] = dp_coin[residual_amount] + dp_coin[sub_amount]
            
        return dp_coin[-1]
    
if __name__ == "__main__":
    coins = [1,2,5]
    amount = 5

    solution = Solution()
    res = solution.change(amount, coins)

    print(res)