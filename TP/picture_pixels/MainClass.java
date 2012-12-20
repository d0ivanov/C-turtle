package org.elsys.robotics;

import java.awt.image.*;
import java.io.IOException;

public class MainClass {

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		ProcessImage imagePixel = new ProcessImage();
		BufferedImage image = null;
		image = imagePixel.openImage("/home/smithie/test.jpg");
		int redCount = imagePixel.calcPixelOccurance(image);
		int size = imagePixel.getSize(image);
		System.out.println((float)redCount / size * 100 + "%");
	}

}
