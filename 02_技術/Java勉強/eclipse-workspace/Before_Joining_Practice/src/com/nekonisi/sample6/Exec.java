package com.nekonisi.sample6;

import java.io.FileNotFoundException;

/**
 * @author nl_konishi
 * Step6���̎��ۂ̏������L�q����N���X
 */
public class Exec {
	
	/**
	 * Step6�̏������L�q���郁�\�b�h
	 */
	public void exec() throws FileNotFoundException{
		
		try {
			System.out.println("Step6 ���i���R�[�h�Ǎ��݃v���O�������J�n���܂��B...\r\n");
			
			// ���i���R�[�h�Ăяo���p�̃N���X���C���X�^���X��
			ProductRecord productRecord = new ProductRecord();
			productRecord.ReadFile();
			System.out.println(productRecord.getReadString(1));
			
		} catch (Exception e) {
			// TODO �����������ꂽ catch �u���b�N
			System.out.println("Step6�̎��s���ɃG���[���������܂����B");
			e.printStackTrace();
			throw e;
		} 
	}
}
