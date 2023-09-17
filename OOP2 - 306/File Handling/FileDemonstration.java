import java.io.File;

public class FileDemonstration {
    public void analyzePath(String path){
        File name = new File(path);

        if(name.exists()){
            System.out.printf("%s%s\n%s\n%s\n%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s",
                    name.getName(), " exists",
                    (name.isFile() ? "is a file" : "is not a file"),
                    (name.isDirectory() ? "is a directory" : "is not a directory"),
                    (name.isAbsolute() ? "is absolute path" : "is not absolute path"),
                    "Last modified: ", name.lastModified(),
                    "Length: ", name.length(),
                    "Path: ", name.getPath(),
                    "Absolute path: ", name.getAbsolutePath(),
                    "Parent: ", name.getParent());
            if(name.isDirectory()){
                String directory[] = name.list();
                System.out.println("\n\nDirectory contents: \n");

                for(String directoryName: directory){
                    System.out.printf("%s\n", directoryName);
                }
            }
        }
        else{
            System.out.printf("%s %s", path, "does not exist.");
        }
    }
}