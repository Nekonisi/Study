  
# Grid  
  
## 概要  
  
グリッド構成で要素を配置する  
  
## 詳細説明  
  
Gridはグリッド構成で要素を配置する型です。  
  
Gridは、すべての子の要素を包括するほど大きなセルという格子を作成します。  
そして、左から右へ作成したセルを配置します。  
※ (0,0)の要素は左上に配置される。  
  
Gridのデフォルトの列数は4列で、行数は必要な分だけ作成されます。  
行数と列数は、rows, または, columnsプロパティで設定可能です。  
  
### サンプルコード  
  
	Grid {  
	    columns: 3  
	    spacing: 2  
	    Rectangle { color: "red"; width: 50; height: 50 }  
	    Rectangle { color: "green"; width: 20; height: 50 }  
	    Rectangle { color: "blue"; width: 50; height: 20 }  
	    Rectangle { color: "cyan"; width: 50; height: 50 }  
	    Rectangle { color: "magenta"; width: 10; height: 10 }  
	}  
  
Gridの要素は、自動的に格子状に配置されます。  
  
Gridの中にvisible=falseの要素がある場合やwidthかheightがゼロの要素がある場合    
その要素は展開されませんし、Column内で可視化されることはありません。    
Column内で要素が自動的に縦に配置された場合は、x,yプロパティや、    
anchorsプロパティを設定をしないでください。    
もし、設定する必要がある場合には、Gridを使用せずに配置を行ってください。    
    
Positionerで取り付けられた要素をColumn内で使用する際は注意してください。    
Column内でより詳細に配置を行う際は、[Item Positioners](http://doc.qt.io/qt-5/qtquick-positioning-layouts.html)を参照してください。    
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
    
### collumnSpacing		qreal  
  
列間の空間をピクセルで設定します。  
このプロパティが明示的に設定されなかった場合、spacingの値が設定されます。  
デフォルト値は設定されていません。  
  
### columns		int  
  
グリッド内の列数を設定します。  
デフォルト値は4です。  
  
### effectiveHorizontalItemAlignment		enumeration  
  
Grid内の水平方向と垂直方向の並びを設定する。  
デフォルト値は下記の通り  
- 垂直方向はtop  
- 水平方向は、layoutDirectionプロパティに準ずる。  
  
たとえば、layoutDirectionがLeftToRightならば、要素は右に並べられる。  
  
	  
LayoutMirroring::enabledまたは、layoutDirectionを有効にした状態でミラーリングを使用した場合  
水平要素もまた、ミラーリングされる。  
しかし、horizontalItemAlignmentが変更されていない場合、  
有効な水平要素や、読み込み専用のeffectiveHorizontalItemAligmentへの問い合わせが行われる。  
  
### effectiveLayoutDirection		enumeration  
  
gridの有効なレイアウト方向を設定します。  
  
LayoutMirroring::enabledが有効な場合、Grid内の位置設定はミラーリングが有効になる。  
しかし、layoutDirectionの設定は変更されない。  
  
### flow		enumeration  
  
gridのレイアウトの流れを設定します。  
  
設定可能な値  
  
- Grid.LeftToRight (デフォルト値) : 次のlayoutDirectionに位置設定される。その際に、次のラインにラップされる。  
- Grid.TopToBottom : 上から下へ配置される。その際に、次の列でラップされる。  
  
### horizontalItemAlignment		enumeration  
  
グリッド内に水平、垂直に要素を配置する。  
デフォルト値、垂直方向には要素はtopｈへ配置される。  
水平方向は、GridのlayoutDirectionに準ずる。 たとえば、layoutDirectionがLeftToRightの時、  
要素は左に整列する。  
  
LayoutMirroring::enabledまたは、layoutDirectionを有効にした状態でミラーリングを使用した場合  
水平要素もまた、ミラーリングされる。  
しかし、horizontalItemAlignmentが変更されていない場合、  
有効な水平要素や、読み込み専用のeffectiveHorizontalItemAligmentへの問い合わせが行われる。  
  
### layoutDirection		enumeration  
  
- layoutのレイアウト方向を設定する。  
  
- Qt.LeftToRight (デフォルト値) : Gridのflowプロパティに従って、topからbottom, leftからrightへ配置される。  
- Qt.RightToLeft : Gridのflowプロパティに従って、topからbottom, rightからleftに配置される。  
  
### leftPadding 	 real    
    
左の要素からのパディングを設定します。    
    
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
    
右の要素からのパディングを設定します。    
  
### rowSpacing		qreal  
  
行内の要素の空白感覚をピクセルで設定する・  
  
設定値がない場合はSpacingが設定される。  
  
### rows		int  
  
grid内の行の中の要素数を設定する。  
Grid内に十分な横幅がない場合は、widthには0が設定される。  
  
spacing		qreal  
  
The spacing is the amount in pixels left empty between adjacent items. The amount of spacing applied will be the same in the horizontal and vertical directions. The default spacing is 0.  
  
The below example places a Grid containing a red, a blue and a green rectangle on a gray background. The area the grid positioner occupies is colored white. The positioner on the left has the no spacing (the default), and the positioner on the right has a spacing of 6.  
  
### topPadding 	 real    
    
周りの要素からのパディングを設定します。    
  
### verticalItemAlignment : enumeration  
  
Sets the horizontal and vertical alignment of items in the Grid. By default, the items are vertically aligned to the top. Horizontal alignment follows the layoutDirection of the Grid, for example when having a layoutDirection from LeftToRight, the items will be aligned on the left.  
  
The valid values for horizontalItemAlignment are, Grid.AlignLeft, Grid.AlignRight and Grid.AlignHCenter.  
  
The valid values for verticalItemAlignment are Grid.AlignTop, Grid.AlignBottom and Grid.AlignVCenter.  
  
The below images show three examples of how to align items.  
  
		  
When mirroring the layout using either the attached property LayoutMirroring::enabled or by setting the layoutDirection, the horizontal alignment of items will be mirrored as well. However, the property horizontalItemAlignment will remain unchanged. To query the effective horizontal alignment of items, use the read-only property effectiveHorizontalItemAlignment.   
  
  
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
    
