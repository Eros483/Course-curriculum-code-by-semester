package faculty;

protected class FacultyDatabase extends UniversityMemberDatabase {
    public FacultyDatabase(int ID, String Name, String Phone) {
        super(ID, Name, Phone);
    }

    public String getRole() {
        return "Faculty";
    }

    public void addMember() {
        addToMembersList(getName());
    }

    public String getMembers() {
        return getAllMembers();
    }
}
