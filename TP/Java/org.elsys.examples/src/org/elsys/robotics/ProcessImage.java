package org.elsys.robotics;

import java.awt.image.*;
import javax.imageio.*;
import java.io.File;
import java.io.IOException;

public class ProcessImage {

	public int calcPixelOccurance(BufferedImage image) {
		int maxX = image.getWidth();
		int maxY = image.getHeight();
		int redCount = 0;
		String hexCode = null;
		for (int x = 0; x < maxX; x++) {
			for (int y = 0; y < maxY; y++) {
				hexCode = Integer.toHexString(image.getRGB(x, y)).toUpperCase();
				if (hexCode.equals("FFFF0000")) {
					redCount++;
				}
			}
		}
		return redCount;
	}

	public BufferedImage openImage(String name) throws IOException {
		File imageFile = new File(name);
		BufferedImage image = ImageIO.read(imageFile);
		return image;
	}

	public int getSize(BufferedImage image) {
		return image.getWidth() * image.getHeight();
	}
}
