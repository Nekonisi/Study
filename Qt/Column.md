  
# Column  
  
## 概要  
  
- 子の要素を1つの列に配置する。  
  
## プロパティ  
  
### add		Transition   
  
positionerに追加されるアイテムに対して実行する変化を設定します。  
  
positionerに対して、下記が適用されます。  
  
- アイテムは、作成またはポジショナーが作成されたあとの子要素としてリペアレントされる。  
- 子要素のvisibleプロパティはfalseからtrueに変化する。  
  
この遷移はViewTransitionプロパティを使用することで、より多くの詳細情報を取得することができます。  
ViewTransitionの詳細は、[ViewTransitionのドキュメント](http://doc.qt.io/qt-5/qml-qtquick-viewtransition.html)を参照してください。  
  
ノート: この遷移は対象の要素がpositionerの一部であった時には適用されません。  
このようなケースの場合、populateプロパティを利用してください。  
  
### bottomPadding 	 real  
  
周りの要素からのパディングを設定します。  
  
### leftPadding 	 real  
  
周りの要素からのパディングを設定します。  
  
### move 	 Transition  
  
- positioner内で移動するアイテムに対して実行する変化を設定します。  
  
positionerに対して、下記が適用されます。  
  
- 追加、削除等でpositioner内の他の子要素が変化した場合、子要素も移動します。  
- positioner内のほかの要素がリサイズされた場合、子要素も再配置されます。  
  
追加された要素に関する詳細情報にはViewTransitionプロパティを使用することができます。  
ViewTransitionの詳細は、[ViewTransitionのドキュメント](http://doc.qt.io/qt-5/qml-qtquick-viewtransition.html)を参照してください。  
  
ノート: この遷移は対象の要素がpositionerの一部であった時には適用されません。  
このようなケースの場合、populateプロパティを利用してください。  
  
### padding 	 real  
  
周りの要素からのパディングを設定します。  
  
### populate 	 Transition  
  
作成された時点でpositionerの一部であるアイテムに対して実行する変化を設定します。  
この変化はpositionが最初に作成された時に実行されます。  
  
この遷移はViewTransitionプロパティを使用することで、より多くの詳細情報を取得することができます。  
ViewTransitionの詳細は、[ViewTransitionのドキュメント](http://doc.qt.io/qt-5/qml-qtquick-viewtransition.html)を参照してください。  
  
### rightPadding 	 real  
  
周りの要素からのパディングを設定します。  
  
### spacing 	 real  
  
隣接したアイテムの間の空白のピクセル値です。 デフォルト値は0です。  
  
### topPadding 	 real  
  
周りの要素からのパディングを設定します。  
  
## シグナル  
  
### positioningComplete()  
  
positioningが終了した時にシグナルが発せられます。  
同様のハンドラに、[onPositioningComplete]があります。  
  
## メソッド  
  
### forceLayout()  
  
コラムは、通常1フレームにつき1度子要素を配置します。  
つまり、スクリプトブロック内では、基礎となる子が変更された可能性がありますが、Columnはまだそれに応じて更新されていない可能性があります。  
  
このメソッドは、子の未処理の変更にすぐに対応します。  
  
ノート: このメソッドはコンポーネントの描画が終了したあとにのみ呼び出してください。  
  
## 詳細説明  
  
Columnを使用すれば単一行内に要素を配置する型です。  
Columnはanchorsプロパティを使用せずに縦に要素を配置する際に便利です。  
  
下記は異なる3つのRectangleを含むColumnのコードです。  
  
	Column {  
	    spacing: 2  
	  
	    Rectangle { color: "red"; width: 50; height: 50 }  
	    Rectangle { color: "green"; width: 20; height: 50 }  
	    Rectangle { color: "blue"; width: 50; height: 20 }  
	}  
  
コラムは自動的にこれらのアイテムを縦に編成します。  
  
コラムの中にvisible=falseの要素がある場合やwidthかheightがゼロの要素がある場合  
その要素は展開されませんし、Column内で可視化されることはありません。  
Column内で要素が自動的に縦に配置された場合は、yプロパティや、  
anchors.top, anchors.bottom, anchors.verticalCenter,fill等の垂直位置を指定するプロパティを設定をしないでください。  
もし、設定する必要がある場合には、Columnを使用せずに配置を行ってください。  
  
Positionerで取り付けられた要素をColumn内で使用する際は注意してください。  
Column内でより詳細に配置を行う際は、[Item Positioners](http://doc.qt.io/qt-5/qtquick-positioning-layouts.html)を参照してください。  
  
## Transitionsの使用法  
  
Column内での、追加、移動、等の変化に対してアニメーションを付けることができます。  
  
下記は例です。  
  
	Column {  
	    spacing: 2  
	  
	    Rectangle { color: "red"; width: 50; height: 50 }  
	    Rectangle { id: greenRect; color: "green"; width: 20; height: 50 }  
	    Rectangle { color: "blue"; width: 50; height: 20 }  
	  
	    move: Transition {  
	        NumberAnimation { properties: "x,y"; duration: 1000 }  
	    }  
	  
	    focus: true  
	    Keys.onSpacePressed: greenRect.visible = !greenRect.visible  
	}  
	  
この例では、[スペースキー]と緑色のRectangleのvisibleプロパティが結び付けられています。  
緑色のRectangleが出現、消失すると、青色のRectangleが自動的に移動します。  
  
