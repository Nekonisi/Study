package com.nekonisi.sample6;

import java.io.FileNotFoundException;

/**
 * @author nl_konishi
 * Step6内の実際の処理を記述するクラス
 */
public class Exec {
	
	/**
	 * Step6の処理を記述するメソッド
	 */
	public void exec() throws FileNotFoundException{
		
		try {
			System.out.println("Step6 商品レコード読込みプログラムを開始します。...\r\n");
			
			// 商品レコード呼び出し用のクラスをインスタンス化
			ProductRecord productRecord = new ProductRecord();
			productRecord.ReadFile();
			System.out.println(productRecord.getReadString(1));
			
		} catch (Exception e) {
			// TODO 自動生成された catch ブロック
			System.out.println("Step6の実行中にエラーが発生しました。");
			e.printStackTrace();
			throw e;
		} 
	}
}
