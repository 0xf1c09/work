package com.example.demo;

import com.rtf.ffmpeg.JNI;
import org.junit.Test;

public class FFmpegJNITest {
	public static void main(String[] args) {
		JNI jni = new JNI();
		try {
			jni.invokeMethod(args.length, args);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}

