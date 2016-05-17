/* 
 * File:   Utils.h
 * Author: clinm
 *
 * Useful methods to deal with images
 * Created on 17 mai 2016, 13:50
 */

#ifndef UTILS_H
#define	UTILS_H

#include <iostream>
#include <vector>
#include <sstream>

#include <stdlib.h>
#include "CImg.h"
using namespace cimg_library;

class Utils {
public:
    Utils();
    Utils(const Utils& orig);
    virtual ~Utils();

    /**
     * Displays image and waits for being closed
     * @param img   The image to display
     * @param title Optionnal title for the window
     */
    static void displayImage(CImg<>& img, const char* title = "Beautiful image"){
        CImgDisplay main_disp(img, title);
        while (!main_disp.is_closed()){
            main_disp.wait();
        }
    }
    
    /**
     * Imports image stored in 'path' and returns the corresponding grayscale.
     * If an error occured during the import, quits immediatly (exit).
     * @param path  Path to the image
     * @return      Grayscale image
     */
    static CImg<> import(char* path){
        CImg<int> importedImage;
        try{
            importedImage = CImg<>(path);
        }catch(const cimg_library::CImgIOException &){
            std::cerr << "Error during import. FilePath: " << path << std::endl;
            exit(1);
        }

        // translate into grayscale. If spectrum is equal to one,
        // already in gray.
        if(importedImage._spectrum > 1){
            importedImage = importedImage.get_RGBtoYCbCr().get_channel(0);
        }
        
        return importedImage;
    }
    
    /**
     * Stores all images contained in list in path_'index'.png when index starts
     *  from 0 and increases
     * @param path Path where images will be written (can contains beginning of
     *             path's name (path/to/file/beginningFileName)
     * @param list  All images to be stored
     */
    static void exportAll(const char* path, std::vector< CImg<>* > list){
        int index = 0;
        for(std::vector< CImg<>* >::iterator it = (list.begin()++); it != list.end(); it++){
            // create file's name
            std::stringstream ss;
            ss << path << "_" << index << ".png";
            
            (*it)->save(ss.str().c_str());
            index++;
        }
    }
    
    /**
     * Given a list of images, returns the average image. All images must have
     * the same dimensions.
     * @param list  Images
     * @return      Average images of all images
     */
    static CImg<int> average(std::vector< CImg<>* > list){
        CImg<int> res(*list.at(0));
        for(std::vector< CImg<>* >::iterator it = (list.begin()++); it != list.end(); it++){
            res += (**it);
        }
        
        return res / list.size();
    }
    
private:

};

#endif	/* UTILS_H */
