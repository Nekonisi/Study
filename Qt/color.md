# 色の指定について

## 概要

- QMLにおける色の指定方法をまとめる

## 色の指定方法

- ARGBで指定する方法

### サンプル

	Rectangle {
	    color: "#FF0000"
	    y: 80; width: 40; height: 40
	}

	Rectangle {
	    color: "#800000FF"
	    y: 120; width: 40; height: 40
	}

- SVG color Nameで指定する方法
- [使用できるColorKeyWord一覧](https://www.w3.org/TR/SVG/types.html#ColorKeywords)

### サンプル

	Rectangle {
	    color: "steelblue"
	    width: 40; height: 40
	}
	Rectangle {
	    color: "transparent"
	    y: 40; width: 40; height: 40
	}

- [参考](http://doc.qt.io/qt-5/qml-color.html)

以上
