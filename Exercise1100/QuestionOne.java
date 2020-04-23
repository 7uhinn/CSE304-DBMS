
//STEP 1. Import required packages
import java.sql.*;

public class QuestionOne {
    // JDBC driver name and database URL
    static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver";
    static final String DB_URL = "jdbc:mysql://localhost/ex12";

    // Database credentials
    static final String USER = "root";
    static final String PASS = "1204";

    public static void main(String[] args) {
        Connection conn = null;
        Statement stmt = null;
        try {
            // STEP 2: Register JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // STEP 3: Open a connection
            System.out.println("Connecting to a selected database...");
            conn = DriverManager.getConnection(DB_URL, USER, PASS);
            System.out.println("Connected database successfully...");

            // STEP 4: Execute a query
            System.out.println("Creating table in given database...");
            stmt = conn.createStatement();

            String emp = "create table emp" + "(eno int," + "ename varchar(10)," + "eage int," + "esalary int,"
                    + "departno int," + "supereno int," + "primary key(eno))";
            String dep = "create table dep" + "(depno int," + "depname varchar(10)," + "depage int," + "eno int,"
                    + "primary key(depno))";
            String depart = "create table depart(" + "departno int," + "departname varchar(10),"
                    + "location varchar(10)," + "primary key(departno,departname,location))";

            stmt.executeUpdate(emp);
            stmt.executeUpdate(dep);
            stmt.executeUpdate(depart);

            for (int i = 1; i < 21; i = i + 1) {
                String eno = Integer.toString(i);
                String ename = "'"+Character.toString((char)(i+64))+"'";
                String eage = Integer.toString(i*10);
                String esalary = Integer.toString(i*10000);
                String departno = Integer.toString(i%3+1);
                String ins1 = "insert into emp"+"(eno,ename,eage,esalary,departno,supereno)"+"values("+eno+","+ename+","+eage+","+esalary+","+departno+",null)";
                stmt.executeUpdate(ins1);

                String depno = Integer.toString(i);
                String depname = "'"+Character.toString((char)(i+64))+"Dep'";
                String depage = Integer.toString(i*10);
                String ins2 = "insert into dep"+"(depno,depname,depage,eno)"+"values("+depno+","+depname+","+depage+","+eno+")";
                stmt.executeUpdate(ins2);
            }

            for(int i=1;i<4;i=i+1){
                String departno = Integer.toString(i);
                String[] departname = {"'Research'","'Admin'","'Sales'"};
                String[] location = {"'Chennai'","'Delhi'","'Mumbai'"};
                String ins3 = "insert into depart"+"(departno,departname,location)"+"values("+departno+","+departname[i-1]+","+location[i-1]+")";
                stmt.executeUpdate(ins3);
            }

            System.out.println("Created table in given database...");
        } catch (SQLException se) {
            // Handle errors for JDBC
            se.printStackTrace();
        } catch (Exception e) {
            // Handle errors for Class.forName
            e.printStackTrace();
        } finally {
            // finally block used to close resources
            try {
                if (stmt != null)
                    conn.close();
            } catch (SQLException se) {
            } // do nothing
            try {
                if (conn != null)
                    conn.close();
            } catch (SQLException se) {
                se.printStackTrace();
            } // end finally try
        } // end try
        System.out.println("Goodbye!");
    }// end main
}// end QuestionOne