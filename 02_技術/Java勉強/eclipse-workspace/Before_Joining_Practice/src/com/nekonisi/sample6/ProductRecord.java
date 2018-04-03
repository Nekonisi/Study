package com.nekonisi.sample6;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * @author nl_konishi
 * 商品レコードクラス
 */
public class ProductRecord {
	
	// {{ 定数
	/**
	 * テキストファイル、デフォルトの読込みパス
	 */
	private static final String DEFAULT_PATH="D:\\syohin.txt";
	
	/**
	 *  商品コードのバイト数
	 */
	private static final int PRODUCT_CODE_BYTE=5;

	/**
	 * 商品名のバイト数
	 */
	private static final int PRODUCT_NAME_BYTE=40;

	/**
	 * 単価
	 */
	private static final int UNIT_PRICE_BYTE=6;

	/**
	 * 売上数量
	 */
	private static final int SALES_BYTE=3;

	/**
	 * 在庫数
	 */
	private static final int STOCK_BYTE=3;

	/**
	 * 備考
	 */
	private static final int REMARKS_BYTE=42;
	
	// }}
	
	// {{ プロパティ
	
	/**
	 * テキストファイルのパス
	 */
	private String recordFilePath="";
	
	/**
	 * テキストファイルオブジェクト
	 */
	private File txtFile = null;
	
	/**
	 * ファイル内の文字列 添え字は行数
	 */
	private List<String> readString = new ArrayList<String>();
	
	// }}
	

	
	// {{ コンストラクタ
	
	// 
	/**
	 * テキストファイルのパスを指定しないコンストラクタ
	 * デフォルト値として、D:\syohin.txtを指定
	 */
	public ProductRecord() throws FileNotFoundException{
		try {
			//プロパティに引数で指定されたパスを格納
			this.recordFilePath= DEFAULT_PATH;
			this.txtFile = new File(this.recordFilePath);
			
			// ファイルの存在チェック
			if (!txtFile.exists()){
				// ファイルが存在しない場合
				throw new FileNotFoundException("指定されたパスにテキストファイルが見つかりません。");
			}
			
			System.out.println("[" + this.recordFilePath +"]を読み込みました。");

		} catch (Exception e) {
			// TODO: handle exception
			throw e;
		}
	}

	// {{ getter, setter
	public String getRecordFilePath() {
		return recordFilePath;
	}

	public void setRecordFilePath(String recordFilePath) {
		this.recordFilePath = recordFilePath;
	}

	public File getTxtFile() {
		return txtFile;
	}

	public void setTxtFile(File txtFile) {
		this.txtFile = txtFile;
	}

	public String getReadString(int rowNumner) {
		return readString.get(rowNumner);
	}

	public void setReadString(List<String> readString) {
		this.readString = readString;
	}
//	}}
	/**
	 * @param recordFilePath 商品レコードのフルパス
	 * テキストファイルのパスを指定したコンストラクタ
	 */
	public ProductRecord(String recordFilePath) throws FileNotFoundException{
		
		try {
			//プロパティに引数で指定されたパスを格納
			this.recordFilePath=recordFilePath;
			this.txtFile = new File(this.recordFilePath);
			
			// ファイルの存在チェック
			if (!txtFile.exists()){
				// ファイルが存在しない場合
				throw new FileNotFoundException("指定されたパスにテキストファイルが見つかりません。");
			}

			System.out.println("[" + this.recordFilePath +"]を読み込みました。");
		} catch (FileNotFoundException e) {
			throw e;
		}
			
		}
	// }}
	
	// {{ メソッド
	
	/**
	 * 指定ファイルの読込を行う
	 */
	public void ReadFile() {
		try (BufferedReader bufferReader = new BufferedReader(new FileReader(this.txtFile));)
		{
			String readString="";
			while((readString = bufferReader.readLine()) != null){
				this.readString.add(readString);
			}
			bufferReader.close();
			
		} catch (FileNotFoundException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		} catch (IOException e) {
			// TODO 自動生成された catch ブロック
			e.printStackTrace();
		} 		
	}
	
public void DisplayFile() {
	
	
	
	
}
	// }}
}

