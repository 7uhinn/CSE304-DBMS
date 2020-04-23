
//STEP 1. Import required packages
import java.sql.*;

public class QuestionTwo {
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
            stmt = conn.createStatement();

            System.out.println("Running Query number (i)...\n");
            String query1 = "select departno,avg(eage) as avg_age from emp group by departno";

            ResultSet rs1 = stmt.executeQuery(query1);
            // STEP 5: Extract data from result set
            while (rs1.next()) {
                // Retrieve by column name
                int departno = rs1.getInt("departno");
                int avg_age = rs1.getInt("avg_age");

                // Display values
                System.out.print("Department Number: " + departno + "\n");
                System.out.print("Average Age: " + avg_age + "\n\n");
            }

            rs1.close();

            System.out.println("Running Query number (ii)...\n");
            String query2 = "select D.departno, D.departname, D.location, min(X.salary_sum) as least_salary from( select D.departno, sum(E.esalary) as salary_sum from depart as D left join emp as E on D.departno = E.departno group by (D.departno)) as X, depart as D where D.departno = X.departno;";

            ResultSet rs2 = stmt.executeQuery(query2);
            // STEP 5: Extract data from result set
            while (rs2.next()) {
                // Retrieve by column name
                int departno = rs2.getInt("departno");
                String departname = rs2.getString("departname");
                String location = rs2.getString("location");
                int least_salary = rs2.getInt("least_salary");

                // Display values
                System.out.print("Department Number: " + departno + "\n");
                System.out.print("Department: " + departname + "\n");
                System.out.print("Location: " + location + "\n");
                System.out.print("Salary Sum: " + least_salary + "\n\n");
            }

            rs2.close();
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
}// end QuestionTwo