# ABC322
- C  
iv(n)で順に見る、Aのインデックスを保存して超えたらインクリメント  
これでO(n)  

- D  
図形系、嫌いなやつ  
実装に時間かかるためスキップ  

- E  
bitDPだとは分かった、進数変換のスニペットを用意しておこう  
ナップサックDPと似た感じの更新、ただし前の状態を一回コピーして持ってきておく  
for1つでは forでi+1を入れた状態を更新する vs i+1を入れない が競合する


# ABC321
- C  
todo

- D  
todo

- E  
todo


# ABC320
- C  
indexを記憶したうえで、スロットの回す順番を順列で見る

- D  
グラフにしたうえでdfs

- E  
戻る時間と待ち行列をpriority_queueにしてイベントを処理するだけ

---

ここから6問体制

---

# ABC319
- C  
todo

- D  
todo

- E  
todo


# ABC318
- C  
料金をsortしてサイズdのwindowでパスとどっちが安いか比較してsum  
なぜか通った

- D  
頂点集合に対してbitDP  
状態をforにして次に任意の2つを採用するかどうかを埋めていく  

- E  
todo


# ABC317
- C  
nが最大10なのでO(n!)で問題ない  
グラフをg[n1][n2]で構築、訪問順の順列でコストを求めて最大値  

- D  
必要な人数Cと利益でDP  
全議席totalとしてdp(total,0)  
dp[j] = min(dp[j], dp[j-z[i]]+w[i]);

- E  
todo


# ABC315
- C  
max(同じ味同士のmax, 異なる味でのmax)

- D  
todo

- E  
todo
