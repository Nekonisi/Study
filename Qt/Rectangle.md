# Rectangle

## 概要

- 境界線と共に正方形を描画する

### import文

- `import QtQuick 2.7`

## プロパティ

### antialliasing: bool

- アンチエリアジングの有効(true)/無効(false)を設定する。
- デフォルト値はtrue

### border group

#### border.width : int

- Rectangleの枠線の太さを設定する。

#### border.color: color

- Rectangleの枠線の色を設定する。
- 色の指定方法は、シート[color]を参照

#### メモ

- borderで描画された枠線はコンポーネントの配置には影響を与えない。
- 枠線は、描画されたRectangle内で描画される。

### color: color

- Rectangle内を満たす色を指定する
- 色の指定方法は、シート[color]を参照

### gradient: Gradient

- Rectangle内で使用するグラデーションを指定する
- グラデーションの指定方法は、シート[gradient]を参照

### radius: real

- Rectangleの角の半径を指定する
- non-zeroを指定すると円形になる
- 4つの角を一括で指定するため、個別にradiusを指定することはできない。

以上


