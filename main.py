import os
import zipfile


#copy files and folder and compress into a zip file
def	backup(source_folder, target_zip):
    zipf = zipfile.ZipFile(target_zip, "w")
    for subdir, dirs, files in os.walk(source_folder): #The method walk() generates the file names in a directory tree by walking the tree either top-down or bottom-up.
        for file in files:
            zipf.write(os.path.join(subdir, file))
            print (os.path.join(subdir, file))



    print ("Created ", target_zip)


if __name__ =='__main__':
    print ('Starting execution')

    #compress to zip

    source_folder = 'E:\\projects'
    target_zip = 'E:\\backups.zip'
    backup(source_folder, target_zip)

    print ('Ending execution')